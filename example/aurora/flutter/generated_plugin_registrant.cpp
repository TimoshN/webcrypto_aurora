//
//  Generated file. Do not edit.
//
#include <flutter/flutter_aurora.h>
#include <webcrypto_aurora/webcrypto_plugin.h>

#include "generated_plugin_registrant.h"

namespace aurora {
void RegisterPlugins() {
  flutter::PluginRegistrar* registrar = GetPluginRegistrar();
  WebcryptoPlugin::RegisterWithRegistrar(registrar);
}
}
