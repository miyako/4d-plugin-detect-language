# 4d-plugin-detect-language
Detect text language, using TLD (by chromium)

##Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|🆗|🆗|🚫|🚫|

Commands
---
```c
// --- CLD
CLD Detect language
```

Examples
---
```
$text:="日本語ですけど何か"

  //simple call
$reliable:=CLD Detect language ($text;$langName;$langCode)

ARRAY TEXT($language3;0)
ARRAY LONGINT($percent3;0)
ARRAY REAL($score3;0)

$text:="c'est la vie"

  //advanced call
$reliable:=CLD Detect language ($text;$langName;$langCode;\
CLD Is plain text;\
$language3;$percent3;$score3)
```
---
