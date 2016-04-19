CLD

#isysroot
export CCFLAGS="-arch x86_64"
export CXXFLAGS="-arch x86_64"
export CFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk -mmacosx-version-min=10.8"
export LDFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk -mmacosx-version-min=10.8"
export CPPFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk -mmacosx-version-min=10.8"

---

export CCFLAGS="-arch i386"
export CXXFLAGS="-arch i386"
export CFLAGS="-arch i386 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk -mmacosx-version-min=10.6"
export LDFLAGS="-arch i386 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk -mmacosx-version-min=10.6"
export CPPFLAGS="-arch i386 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk -mmacosx-version-min=10.6"

export CC="g++"
export CFLAGS="-arch i386"
export LDFLAGS="-arch i386"
export CXXFLAGS="-arch i386"

---

#to create dylib

g++ -dynamiclib -undefined suppress -flat_namespace *.o -o libcld.dylib

---

windows

undefine UNICODE to avoid conflict

explicitly save unittest_data.h in utf-8

uncomment the include for util/utf8/utf8statetable.h

ignore warning 4556