#include <napi.h>
#include <unicode/timezone.h>
#include <unicode/unistr.h>

namespace icu_iana_from_windows
{
    Napi::String ConvertWindowsToIANA(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        std::string result,
            windowsTimezoneId,
            territory = "";

        if (info.Length() < 1 || !info[0].IsString() || info[0].As<Napi::String>().Utf8Value().empty())
        {
            Napi::Error::New(env, "Expected a non-empty Windows timezone ID as the first argument")
                .ThrowAsJavaScriptException();
            return Napi::String::New(env, "");
        }
        else
        {
            windowsTimezoneId = info[0].As<Napi::String>().Utf8Value();
        }

        if (info.Length() > 1 && info[1].IsString())
        {
            territory = info[1].As<Napi::String>().Utf8Value();
        }

        icu::UnicodeString ianaId;
        UErrorCode errorCode = U_ZERO_ERROR;

        icu::TimeZone::getIDForWindowsID(
            icu::UnicodeString::fromUTF8(windowsTimezoneId),
            territory.empty() ? nullptr : territory.c_str(),
            ianaId,
            errorCode);

        if (U_FAILURE(errorCode) || ianaId.isEmpty())
        {
            Napi::Error::New(env, "Failed to convert Windows timezone ID to IANA")
                .ThrowAsJavaScriptException();
            return Napi::String::New(env, "");
        }

        ianaId.toUTF8String(result);
        return Napi::String::New(env, result);
    }

    Napi::Boolean CheckFullICUSupport(const Napi::Env &env)
    {
        Napi::String locale = Napi::String::New(env, "es");
        Napi::Object options = Napi::Object::New(env);
        options.Set("month", Napi::String::New(env, "long"));

        Napi::Object intl = env.Global().Get("Intl").As<Napi::Object>();
        Napi::Function dateTimeFormatConstructor = intl.Get("DateTimeFormat").As<Napi::Function>();

        Napi::Object formatter = dateTimeFormatConstructor.New({locale, options});
        std::string result = formatter.Get("format").As<Napi::Function>().Call(formatter, {Napi::Date::New(env, 9e8)}).As<Napi::String>();
        return Napi::Boolean::New(env, result == "enero");
    }

    Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        // check if node is full-icu
        if (!env.Global().Get("Intl").IsObject())
        {
            Napi::Error::New(env, "Node.js is not built with full ICU support")
                .ThrowAsJavaScriptException();
            return exports;
        }

        if (!CheckFullICUSupport(env).Value())
        {
            Napi::Error::New(env, "Node.js is not built with full ICU support")
                .ThrowAsJavaScriptException();
            return exports;
        }

        exports.Set("convertWindowsToIana", Napi::Function::New(env, ConvertWindowsToIANA));
        return exports;
    }

    NODE_API_MODULE(icu_iana_from_windows, Init)
}