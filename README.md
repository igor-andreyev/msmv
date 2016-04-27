# msmv
Usage: `./msmv_framework --input input_directory --extension extension --output output_directory --count image_count [--transformation Transformation [TransformationOptions | ...] | ... ]`

Min and max values should be specified for each numerical transformation's option.
# Currently Supported Transformations:
* BrightAndContrast(aplha, bias): alpha * x + bias
* SaltPepperNoise(black, white): 
* GaussianNoise(mean, stddev):
* GaussianBlur(windows_x, windows_y, stddev):
* Compresssion(compression_type, level): only JPEG or PNG supported
* Resize(size_x, size_y):
* LensDistort(k1,k2,p1,p2):





Sample run: 
`./msmv_framework --transformation GaussianNoise 120 128 80 90  --input ./CroppedYale/yaleB02 --output ./test_output --count 10 --extension pgm`
