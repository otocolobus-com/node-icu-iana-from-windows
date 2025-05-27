#include <napi.h>
#include <unicode/timezone.h>
#include <unicode/unistr.h>

Napi::String ConvertWindowsToIANA(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    std::string result,
        windowsTimezoneId,
        territory = "ZZ";

    if (info.Length() < 1 || !info[0].IsString())
    {
        Napi::Error::New(env, "Expected a Windows timezone ID as the first argument")
            .ThrowAsJavaScriptException();
        return Napi::String::New(env, "");
    }

    if (info.Length() > 1 && info[1].IsString())
    {
        territory = info[1].As<Napi::String>().Utf8Value();
    }

    icu::UnicodeString ianaId;
    UErrorCode errorCode = U_ZERO_ERROR;

    icu::TimeZone::getIDForWindowsID(
        icu::UnicodeString::fromUTF8(windowsTimezoneId),
        territory.c_str(),
        ianaId,
        errorCode);

    if (U_FAILURE(errorCode) || ianaId.isEmpty())
    {
        Napi::Error::New(env, "Failed to convert Windows ID to IANA ID").ThrowAsJavaScriptException();
        return Napi::String::New(env, "");
    }

    ianaId.toUTF8String(result);
    return Napi::String::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("convertWindowsToIana", Napi::Function::New(env, ConvertWindowsToIANA));
    return exports;
}

NODE_API_MODULE(icu_iana_from_windows, Init)
