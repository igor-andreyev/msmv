# msmv
Usage: `./msmv_framework -i input_directory -o output_directory -c image_count [-t Transformation [TransformationOptions | ...] | ... ]`

# Currently Supported Transformations:
* BrightAndContrast(aplha, bias): alpha * x + bias
* SaltPepperNoise(black, white): 
* GaussianNoise(mean, stddev):
* GaussianBlur(windows_x, windows_y, stddev):
* Compresssion(compression_type, level): only JPEG or PNG supported
* Resize(size_x, size_y):
* LensDistort(k1,k2,p1,p2):





Sample run: 
`./msmv_framework -t GaussianNoise 128 80  -t SaltPepperNoise 10 245 -t GaussianBlur 5 5 0.8 -i ./CroppedYale/yaleB02 -o ./test_output -c 10`
