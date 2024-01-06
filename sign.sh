PLUGIN_NAME="Simple EQ"
APPLE_DEVELOPER="Developer ID Application: Jesus Valdez (Q6UGP2R4MC)"

echo "Signing VST3..."
codesign --force --deep --options runtime --sign "${APPLE_DEVELOPER}" "${PLUGIN_NAME} macOS/${PLUGIN_NAME}.vst3"

echo "Signing AU..."
codesign --force --deep --options runtime --sign "${APPLE_DEVELOPER}" "${PLUGIN_NAME} macOS/${PLUGIN_NAME}.component"

echo "Signing Scanner..."
codesign --force --deep --options runtime --sign "${APPLE_DEVELOPER}" "${PLUGIN_NAME} macOS/${PLUGIN_NAME}.app"

echo "Zipping..."
zip -r "${PLUGIN_NAME} macOS.zip" "${PLUGIN_NAME} macOS"