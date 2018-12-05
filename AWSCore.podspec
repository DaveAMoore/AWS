Pod::Spec.new do |s|
    s.name         = "AWSCore"
    s.version      = "2.6.32"
    s.summary      = "Collection of AWS frameworks for macOS and iOS."
    s.homepage     = "https://github.com/DaveAMoore/AWS"
    s.license      = "Apache License, Version 2.0"
    s.author       = { "David Moore" => "mooredev@me.com" }
    s.source       = { :git => "https://github.com/DaveAMoore/AWS.git", :tag => "v2.6.32" }
    
    s.requires_arc = true
    s.frameworks   = "CoreGraphics", "Foundation", "SystemConfiguration", "Security"
    s.ios.frameworks = "UIKit"
    s.osx.frameworks = "AppKit"
    s.libraries    = "z", "sqlite3"
    
    s.ios.deployment_target = "9.3"
    s.osx.deployment_target = "10.12"
    
    s.source_files = "AWSCore/*.{h,m}", "AWSCore/**/*.{h,m}"
    s.private_header_files = "AWSCore/XMLDictionary/**/*.h", "AWSCore/XMLWriter/**/*.h", "AWSCore/FMDB/AWSFMDatabase+Private.h", "AWSCore/Fabric/*.h", "AWSCore/Mantle/extobjc/*.h", "AWSCore/CognitoIdentity/AWSCognitoIdentity+Fabric.h"
end
