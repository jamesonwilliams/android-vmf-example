// Copyright (C) 2014, Intel Corporation, all rights reserved.

/*!
* \file rwconst.hpp
* \brief Constants definitions for %IReader and %IWriter interface implementations
* \details The file contains constants declarations that are required for %IReader and %IWriter interface implementations (e.g. %XMLReader)
*/

#pragma once

#ifndef __VMF_RWCONST_H__
#define __VMF_RWCONST_H__

#define TAG_VMF "vmf"
#define TAG_VIDEO_SEGMENT_ARRAY "segment-array"
#define TAG_VIDEO_SEGMENT "segment"
#define TAG_SCHEMA_ARRAY "schema-array"
#define TAG_SCHEMA "schema"
#define TAG_CLASS "class"
#define TAG_CLASS_ARRAY "class-array"
#define TAG_FIELD "field"
#define TAG_FIELD_ARRAY "field-array"
#define TAG_METADATA_ARRAY "metadata-array"
#define TAG_METADATA "metadata"
#define TAG_METADATA_REFERENCE_ARRAY "reference-array"
#define TAG_METADATA_REFERENCE "reference"

#define ATTR_NAME "name"
#define ATTR_VALUE "value"
#define ATTR_ID "id"

#define ATTR_SEGMENT_TITLE "title"
#define ATTR_SEGMENT_FPS "fps"
#define ATTR_SEGMENT_TIME "time"
#define ATTR_SEGMENT_DURATION "duration"
#define ATTR_SEGMENT_WIDTH "width"
#define ATTR_SEGMENT_HEIGHT "height"

#define ATTR_SCHEMA_AUTHOR "author"

#define ATTR_FIELD_TYPE "type"
#define ATTR_FIELD_OPTIONAL "optional"

#define ATTR_REFERENCE_UNIQUE "unique"
#define ATTR_REFERENCE_CUSTOM "custom"

#define ATTR_VMF_NEXTID "nextId"
#define ATTR_VMF_FILEPATH "filepath"
#define ATTR_VMF_CHECKSUM "checksum"
#define ATTR_METADATA_SCHEMA "schema"
#define ATTR_METADATA_CLASS "class"
#define ATTR_METADATA_FRAME_IDX "frameindex"
#define ATTR_METADATA_NFRAMES "nframes"
#define ATTR_METADATA_TIMESTAMP "timestamp"
#define ATTR_METADATA_DURATION "duration"

template <typename T>
T ToNumber(const std::string& Str)
{
	T Number;
	std::stringstream S(Str);
	S >> Number;
	return Number;
}
template <typename T>
std::string ToString(T Number)
{
	std::stringstream S;
	S << Number;
	return S.str();
}
#endif /* __VMF_RWCONST_H__ */
