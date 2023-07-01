/*
File:           data_input_output.cpp
Last changed:   27/06/2023 23:15
Purpose:        simple code to read and write images and videos       
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToCompile:   cmake .. && make
	HowToExecute:   ./data_input_output --video_file=/path/to/video.mp4 --image_file=/path/to/image.jpg           
*/

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){

    cv::CommandLineParser parser(argc, argv,
        "{video_file|../samples/gangnam.mp4|Path to the video file}"
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
    std::string video_file = parser.get<std::string>("video_file");

    std::string image_file = parser.get<std::string>("image_file");

    //entrada e saida de dados:
    cv::Mat image_color= cv::imread(image_file);
    cv::Mat image_gray= cv::imread(image_file, cv::IMREAD_GRAYSCALE);
    
    if (image_file.empty() || image_gray.empty())
    {
        std::cout << "Não foi possível abrir a imagem." << std::endl;
        return -1;
    }

    //DADOS DOS PIXLELS DA IMAGEM COLORIDA
    for (int row = 0; row < image_color.rows; ++row) {
        for (int col = 0; col < image_color.cols; ++col) {
            // Acessar o valor do pixel na posição (row, col)
            cv::Vec3b pixel = image_color.at<cv::Vec3b>(row, col);

            // Imprimir os valores dos canais de cor, BGR em vez de RGB otarisse
            std::cout << "Pixel na posição (" << row << ", " << col << "): ";
            std::cout << "R = " << static_cast<int>(pixel[2]) << ", ";
            std::cout << "G = " << static_cast<int>(pixel[1]) << ", ";
            std::cout << "B = " << static_cast<int>(pixel[0]) << std::endl;
        }
    }

    //DADOS DOS PIXLELS DA IMAGEM CINZA
    for (int row = 0; row < image_gray.rows; ++row) {
        for (int col = 0; col < image_gray.cols; ++col) {
            // Acessar o valor do pixel na posição (row, col)
            uchar pixel_value = image_gray.at<uchar>(row, col);

            // Imprimir o valor do pixel
            std::cout << "Pixel na posição (" << row << ", " << col << "): ";
            std::cout << "Valor = " << static_cast<int>(pixel_value) << std::endl;
        }
    }

    // Mostrar a imagem colorida
    cv::imshow("Imagem colorida:", image_color);
    cv::waitKey(0);

    // Mostrar a imagem em escala de cinza
    cv::imshow("Imagem em escala de cinza:", image_gray);
    cv::waitKey(0);

    //video
    auto video_capture = cv::VideoCapture(video_file);
    //auto video_capture = cv::VideoCapture(0); pegar o socket de video /dev/video0, padrão do linux

    if (!video_capture.isOpened()) {
        std::cerr << "Erro ao abrir o arquivo de vídeo." << std::endl;
        return 1;
    }

    // Loop para exibir cada frame do vídeo, sim tem que mostrar frame por frame kkkk
    // nao opencv nao tem como pegar audio, mais info ffmpeg

    cv::Mat frame;
    while (video_capture.read(frame)) {
        cv::imshow("Video", frame);

        // Aguarda 30 milissegundos e verifica se uma tecla foi pressionada
        // Se 'q' for pressionado, interrompe o loop e fecha a janela
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    // Fecha a janela
    cv::destroyAllWindows();
    return 0;
}