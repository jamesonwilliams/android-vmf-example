/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <string.h>
#include <jni.h>
#include <vmf.hpp>

#ifdef __cplusplus
extern "C" {
#endif
jstring
Java_com_example_hellojni_HelloJni_stringFromJNI( JNIEnv* env, jobject thiz );
#ifdef __cplusplus
}
#endif

jstring
Java_com_example_hellojni_HelloJni_stringFromJNI( JNIEnv* env, jobject thiz )
{
    std::string message("Test Android message");
    vmf::initialize();
    
    // Part 1
    // Save message to manually created file
    vmf::MetadataStream outStream;
    if(!outStream.open("<your_test_file>", vmf::MetadataStream::ReadWrite))
        return env->NewStringUTF("Couldn't open test file (RW)");
    const std::string SCHEMA_NAME("Test Android Schema");
    std::shared_ptr<vmf::MetadataSchema> schema =
        std::make_shared<vmf::MetadataSchema>(SCHEMA_NAME);
    const std::string METADATA_NAME("Test Android Metadata");
    std::shared_ptr<vmf::MetadataDesc> desc =
        std::make_shared<vmf::MetadataDesc>(METADATA_NAME,
                                            vmf::Variant::type_string);
    schema->add(desc);
    try {
        outStream.addSchema(schema);
    } catch (...) {
        // do nothing
    }
    std::shared_ptr<vmf::Metadata> metadataForSaving =
        std::make_shared<vmf::Metadata>(desc);
    metadataForSaving->addValue(message);
    outStream.add(metadataForSaving);
    if(!outStream.save())
        return env->NewStringUTF("Couldn't save message to file..");
    outStream.close();

    // Part 2
    // Read message from file
    vmf::MetadataStream inStream;
    if(!inStream.open("<your_test_file>", vmf::MetadataStream::ReadOnly))
        return env->NewStringUTF("Couldn't open test file (RO)");
    inStream.load();
    vmf::MetadataSet testMetadata = inStream.queryByName(METADATA_NAME);
    std::string readMessage = (std::string) testMetadata.at(0)->at(0);
    vmf::terminate();
    return env->NewStringUTF(readMessage.c_str());
}

