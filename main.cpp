#include <iostream>
#include <fstream>


void borrarEspacios(std::ifstream& file, std::ofstream& fileNoSpaces);

int main()
{
    std::string renglon;
    std::ifstream codigoFuente ("ifcorrecto.txt");
    std::ofstream codigoFuenteSinEspacios("textoavalidar.txt");

    borrarEspacios(codigoFuente, codigoFuenteSinEspacios);

    if(codigoFuente.is_open())
    {
        while(getline(codigoFuente, renglon))
            std::cout << renglon << std::endl;

        codigoFuente.close();
    }
    else std::cout << "No se puede abrir el archivo." << std::endl;

    return 0;
}


void borrarEspacios(std::ifstream& file, std::ofstream& fileNoSpaces)
{
    std::string renglon;

    while(getline(file, renglon))
        {
             std::cout << renglon << std::endl;
             std::remove_if(renglon.begin(), renglon.end(), isspace);
             fileNoSpaces << renglon;
        }
}
