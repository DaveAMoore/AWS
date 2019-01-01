Pod::Spec.new do |s|
    s.name         = "AWSS3"
    s.version      = "2.6.33"
    s.summary      = "Collection of AWS frameworks for macOS and iOS."
    s.homepage     = "https://github.com/DaveAMoore/AWS"
    s.license      = "Apache License, Version 2.0"
    s.author       = { "David Moore" => "mooredev@me.com" }
    s.source       = { :git => "https://github.com/DaveAMoore/AWS.git", :tag => "v2.6.33" }
    
    s.requires_arc = true
    s.pod_target_xcconfig = { "APPLICATION_EXTENSION_API_ONLY" => "YES" }
    
    s.ios.deployment_target = "9.3"
    s.osx.deployment_target = "10.12"
    
    s.dependency "AWSCore", "2.6.33"
    s.source_files = "AWSS3/*.{h,m}"
end
