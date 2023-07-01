cmake_minimum_required(VERSION 3.5)
project(introduction_openCV_filters)

# Procurar a biblioteca OpenCV
find_package(OpenCV REQUIRED)

# Adicionar o diretório de inclusão do OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Listar todos os arquivos de origem
set(SOURCE_FILES
    ./src/check_version.cpp
    ./src/data_input_output.cpp
    ./src/color_remaping.cpp
)

# Gerar um executável para cada arquivo de origem
foreach(SOURCE_FILE ${SOURCE_FILES})

    # Obter o nome do arquivo sem a extensão
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)

    # Definir o nome do executável
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

    # Vincular as bibliotecas necessárias
    target_link_libraries(${EXECUTABLE_NAME} ${OpenCV_LIBS})

endforeach(SOURCE_FILE)
