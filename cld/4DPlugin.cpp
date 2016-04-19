/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : CLD
 #	author : miyako
 #	2016/04/19
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

void PluginMain(PA_long32 selector, PA_PluginParameters params)
{
	try
	{
		PA_long32 pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		CommandDispatcher(pProcNum, pResult, pParams); 
	}
	catch(...)
	{

	}
}

void CommandDispatcher (PA_long32 pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{
	switch(pProcNum)
	{
// --- CLD

		case 1 :
			CLD_Detect_language(pResult, pParams);
			break;

	}
}

// -------------------------------------- CLD -------------------------------------


void CLD_Detect_language(sLONG_PTR *pResult, PackagePtr pParams)
{
	C_TEXT sourceText;
	C_TEXT langName;
	C_TEXT langCode;
	C_LONGINT option;
	ARRAY_TEXT language3;
	ARRAY_LONGINT percent3;
	ARRAY_REAL score3;
	C_LONGINT returnValue;

	sourceText.fromParamAtIndex(pParams, 1);
	option.fromParamAtIndex(pParams, 4);

	bool is_reliable;
	bool do_allow_extended_languages = true;
	bool do_pick_summary_language = false;
	bool do_remove_weak_matches = false;
	bool is_plain_text = option.getIntValue();

	Language language_hint = UNKNOWN_LANGUAGE;
	const char* tld_hint = NULL;
	int encoding_hint = UNKNOWN_ENCODING;//UTF16LE gives poor answer
	
	double _score3[3];
	Language _language3[3];
	int _percent3[3];
	int text_bytes;
	
	void (*_PA_YieldAbsolute)(void) = PA_YieldAbsolute;
	
	CUTF8String src;
	sourceText.copyUTF8String(&src);
	
	Language lang = CompactLangDet::DetectLanguage(0,
																								 (const char*)src.c_str(),
																								 src.size(),
																								 is_plain_text,
																								 do_allow_extended_languages,
																								 do_pick_summary_language,
																								 do_remove_weak_matches,
																								 tld_hint,
																								 encoding_hint,
																								 language_hint,
																								 _language3,
																								 _percent3,
																								 _score3,
																								 &text_bytes,
																								 &is_reliable, _PA_YieldAbsolute);

	CUTF8String languageName = (const uint8_t *)LanguageName(lang);
	CUTF8String languageCode = (const uint8_t *)LanguageCode(lang);
	
	langName.setUTF8String(&languageName);
	langCode.setUTF8String(&languageCode);
	
	returnValue.setIntValue(is_reliable);
	
	language3.setSize(1);
	percent3.setSize(1);
	score3.setSize(1);
	
	for(int i = 0; i < 3; ++i)
	{
		CUTF8String _languageName = (const uint8_t *)LanguageName(_language3[i]);
		language3.appendUTF8String(&_languageName);
		score3.appendDoubleValue(_score3[i]);
		percent3.appendIntValue(_percent3[i]);
	}
	
	langName.toParamAtIndex(pParams, 2);
	langCode.toParamAtIndex(pParams, 3);
	language3.toParamAtIndex(pParams, 5);
	percent3.toParamAtIndex(pParams, 6);
	score3.toParamAtIndex(pParams, 7);
	returnValue.setReturn(pResult);
}
