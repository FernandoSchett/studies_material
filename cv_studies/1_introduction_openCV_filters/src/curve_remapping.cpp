/*
File:           curve_remaping.cpp
Last changed:   27/06/2023 23:15
Purpose:           
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToCompile:   cmake .. && make
	HowToExecute:   ./curve_remaping --image_file=/path/to/image.jpg           
*/

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
	
	cv::CommandLineParser parser(argc, argv,
        "{image_file|../samples/orange_cat.jpg|Path to the image file}");

	if (parser.has("help"))	{
	    parser.printMessage();
	    return 0;
	}
    if (!parser.check())
	{
	    parser.printErrors();
	    return 0;
	}

    std::string image_file = parser.get<std::string>("image_file");

    cv::Mat image_color = cv::imread(image_file);
	
	if (image_color.empty()) {
        std::cout << "Não foi possível abrir a imagem." << std::endl;
        return -1;
    }

	// Filtro Technicolor, converter uma imagem em tons de vermelho e ciano
    
    for (int y = 0; y < image_color.rows; y++) {
        for (int x = 0; x < image_color.cols; x++) {
			// Atenção no ponteiro sacaninha
            cv::Vec3b &pixel = image_color.at<cv::Vec3b>(y, x);
            pixel[0] = pixel[2];  // Componente azul (B) é igual ao componente vermelho (R)
            // O componente verde (G) é mantido inalterado
        }
    }

	cv::imshow("Filtro Technicolor", image_color);
	cv::waitKey(0);

	// Converter a imagem para o espaço de cores HSV
    cv::Mat hsv_image;
    cv::cvtColor(image_color, hsv_image, cv::COLOR_BGR2HSV);
	cv::imshow("Filtro HSV", hsv_image);
	cv::waitKey(0);

    // Extrair o canal de valor (Value)
	std::vector<cv::Mat> hsv_channels;

	// Divide em canais de cores (matrizes) separados 
    cv::split(hsv_image, hsv_channels);

    // Exibir o canal de valor
	for(int i = 0; i < 3; i++) {
    	cv::imshow("Canal de Valor (Value)", hsv_channels[i]);
    	cv::waitKey(0);
	}

	// (HUE) Matiz: Representa o comprimento de onda dominante da cor. O matiz é normalmente descrito como um ângulo ao redor de uma roda de cores, variando de 0 a 360 graus. Neste modelo, 0 graus representa o vermelho, 120 graus representa o verde e 240 graus representa o azul. Os outros valores intermediários representam cores intermediárias.
	// (Saturation sla)Saturação: Refere-se à intensidade ou pureza da cor. A saturação varia de 0 a 100%, onde 0% indica uma cor completamente insaturada (cinza) e 100% representa a versão mais intensa e vibrante da cor.
	//Value (também conhecido como Brilho): Representa o brilho ou luminosidade da cor. O valor varia de 0 a 100%, onde 0% representa o preto (sem luz) e 100% representa o brilho máximo.
	// Ao manipular os valores de matiz, saturação e valor, é possível criar uma ampla gama de cores. Este modelo de cor é frequentemente preferido em relação a outros modelos (como RGB ou CMYK) para certas aplicações, pois oferece uma maneira mais intuitiva de controlar e selecionar cores com base em suas qualidades perceptivas.
	return 0;
}
