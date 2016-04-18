# msmv
Usage: ./msmv_framework -i input_directory -o output_directory -c image_count [-t Transformation [TransformationOptions...] | ... ]

# Currently Supported:
* BrightAndContrast
* SaltPepperNoise
* GaussianNoise
* GaussianBlur




Sample run: 
`./msmv_framework -t GaussianNoise 128 80  -t SaltPepperNoise 10 245 -t GaussianBlur 5 5 0.8 -i ./CroppedYale/yaleB02 -o ./test_output -c 10`
