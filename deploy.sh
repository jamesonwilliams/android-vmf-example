#!/bin/bash

adb logcat -c
ant clean
ant debug
adb uninstall com.example.vmfdemo
adb install -r bin/VmfDemo-debug.apk
adb shell am start -n com.example.vmfdemo/.VmfActivity
adb logcat | grep intel

