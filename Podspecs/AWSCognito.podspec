Pod::Spec.new do |s|
    s.name         = "AWSCognito"
    s.version      = "2.6.32"
    s.summary      = "Collection of AWS frameworks for macOS and iOS."
    s.homepage     = "https://github.com/DaveAMoore/AWS"
    s.license      = "Apache License, Version 2.0"
    s.author       = { "David Moore" => "mooredev@me.com" }
    s.source       = { :git => "https://github.com/DaveAMoore/AWS.git", :tag => "v2.6.32" }
    
    s.requires_arc = true
    s.pod_target_xcconfig = { "APPLICATION_EXTENSION_API_ONLY" => "YES" }
    
    s.ios.deployment_target = "9.3"
    s.osx.deployment_target = "10.12"
    
    s.library      = "sqlite3"
    s.dependency "AWSCore", "2.6.32"
    s.source_files = "AWSCognito/*.{h,m}", "AWSCognito/**/*.{h,m}"
    s.public_header_files = "AWSCognito/*.h", "AWSCognito/CognitoSync/*.h"
    s.private_header_files =  "AWSCognito/Internal/*.h"
end
