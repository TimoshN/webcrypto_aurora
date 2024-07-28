/**
 * SPDX-FileCopyrightText: Copyright 2023 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <webcrypto_aurora/webcrypto_plugin.h>


//#include <flutter/method-channel.h>
//#include <flutter/platform-methods.h>
#include <sys/utsname.h>

namespace PlatformVersion {

constexpr auto Version = "Aurora";

}


WebcryptoPlugin::WebcryptoPlugin(
    PluginRegistrar* registrar,
    std::unique_ptr<MethodChannel> methodChannel
) : m_methodChannel(std::move(methodChannel))
{
    RegisterMethodHandler();
}

void WebcryptoPlugin::RegisterWithRegistrar(PluginRegistrar* registrar)
{
    auto methodChannel = std::make_unique<MethodChannel>(
        registrar->messenger(), "webcrypto",
        &flutter::StandardMethodCodec::GetInstance());


    std::unique_ptr<WebcryptoPlugin> plugin(new WebcryptoPlugin(
        registrar,
        std::move(methodChannel)
    ));

    // Register plugin
    registrar->AddPlugin(std::move(plugin));

}

void WebcryptoPlugin::RegisterMethodHandler()
{


    m_methodChannel->SetMethodCallHandler(
        [this](const MethodCall& call, std::unique_ptr<MethodResult> result) {
            if (call.method_name().compare("getPlatformVersion") == 0) {
                result->Success(onGetPlatformVersion(call));
            }
            else {
                result->Success();
            }
        });


}

std::string WebcryptoPlugin::onGetPlatformVersion(const MethodCall &call)
{
    return PlatformVersion::Version;
}

void WebcryptoPlugin::unimplemented(const MethodCall &call)
{
    //call.SendSuccessResponse(nullptr);
}
