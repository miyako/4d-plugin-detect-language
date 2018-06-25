# 4d-plugin-detect-language
Detect text language, using TLD (by chromium)

### Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|

### Version

<img src="https://cloud.githubusercontent.com/assets/1725068/18940649/21945000-8645-11e6-86ed-4a0f800e5a73.png" width="32" height="32" /> <img src="https://cloud.githubusercontent.com/assets/1725068/18940648/2192ddba-8645-11e6-864d-6d5692d55717.png" width="32" height="32" /> 

## Syntax

```
reliable:=CLD Detect language (text;langName;langCode{option;language3;percent3;score})
```

Parameter|Type|Description
------------|------------|----
text|TEXT|
langName|TEXT|
langCode|TEXT|
option|LONGINT|``CLD Is plain text`` or ``CLD Is HTML``
language3|ARRAY TEXT|
percent3|ARRAY LONGINT|
score3|ARRAY REAL|
reliable|LONGINT|

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
