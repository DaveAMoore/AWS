Pod::Spec.new do |s|
    s.name         = "AWS"
    s.version      = "2.6.32"
    s.summary      = "Collection of AWS frameworks for macOS and iOS."
    s.homepage     = "https://github.com/DaveAMoore/AWS"
    s.license      = "Apache License, Version 2.0"
    s.author       = { "David Moore" => "mooredev@me.com" }
    s.source       = { :git => "https://github.com/DaveAMoore/AWS.git", :tag => "v2.6.32" }
    
    s.requires_arc = true
    
    s.ios.deployment_target = "9.3"
    s.osx.deployment_target = "10.12"
    
    s.subspec "AWSCore" do |aws|
        aws.dependency "AWSCore", "2.6.32"
    end
    
    s.subspec "AWSAutoScaling" do |autoscaling|
        autoscaling.dependency "AWSAutoScaling", "2.6.32"
    end
    
    s.subspec "AWSCognito" do |cognito|
        cognito.dependency "AWSCognito", "2.6.32"
    end
    
    s.subspec "AWSCognitoIdentityProvider" do |identityprovider|
        identityprovider.dependency "AWSCognitoIdentityProvider", "2.6.32"
    end
    
    s.subspec "AWSCognitoIdentityProviderASF" do |identityproviderasf|
        identityproviderasf.dependency "AWSCognitoIdentityProviderASF", "2.6.32"
    end
    
    s.subspec "AWSDynamoDB" do |dynamodb|
        dynamodb.dependency "AWSDynamoDB", "2.6.32"
    end
    
    s.subspec "AWSIoT" do |iot|
        iot.dependency "AWSIoT", "2.6.32"
    end
    
    s.subspec "AWSS3" do |s3|
        s3.dependency "AWSS3", "2.6.32"
    end
    
    s.subspec "AWSSNS" do |sns|
        sns.dependency "AWSSNS", "2.6.32"
    end
    
    s.subspec "AWSSQS" do |sqs|
        sqs.dependency "AWSSQS", "2.6.32"
    end
end
