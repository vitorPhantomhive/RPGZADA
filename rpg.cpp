#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

// TODO Fazer uma forma do jogador ou jogadora escolher sua raça
// TODO Sendo que cada raça tem a possibilidade de  ter mais ou menos atributos que as outras

struct Personagem{
    std::string nome;

    unsigned int energia;
    unsigned int altura;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
};

float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

struct Personagem boasVindasDoJogo(){
    std::cout << "Boas vindas ao nosso mundo!\n";
    std::cout << "Um sentimento de obscuridade tomou conta de nossa terra, \n";
    std::cout << "o rei Demônio dominou as principais forças de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanças decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e não conseguimos nos defender\n";
    std::cout << "precisamos de alguém que nos lidere para a derrocada deste maldito!\n";
    std::cout << "Você é nossa escolha!! E... a propósito... qual é mesmo o seu nome?\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sir " << nome << "!\n";

    struct Personagem eu;

    eu.nome = nome;
    eu.energia = (geraAleatorio() * 90) + 10;
    eu.altura = geraAleatorio() * 300;
    eu.forcaFisica = geraAleatorio() * 100;
    eu.forcaMagica = geraAleatorio() * 50;
    eu.creditos = 26;

    return eu;
}

void mostraStatusDoJogador(struct Personagem &p){

    if(p.energia == 0){
        std::cout << "Você morreu!!!" << std::endl;
        return;
    }

    std::cout << "Você agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia << " de energia com uma força de intensidade " <<
                p.forcaFisica << " e um poder mágico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaCidade(struct Personagem &p){
    
    unsigned int opcao = 0;

    while(opcao < 1 || opcao > 2){
        std::cout << "Você está na rua principal da cidade, nesta rua você vê dois estabelecimentos: Uma quitanda de um lado uma loja de armas do outro.\n Para onde você deseja ir?" << std::endl;
        std::cout << "1-Quitanda\n2-Loja de armas" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;
        
        std::cout << "1-Nada\n2-Comida\n3-Que vá para a p*" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Macarrão (Dá muita energia)\n2-Balinha (Dá pouca energia)" << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 50){
                        p.energia += 50;
                        p.creditos -= 50;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.energia += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Prepare-se para morrer indolente!!!" << std::endl;
            p.energia = p.energia - p.energia;
            return;
        }else{
            std::cout << "Que cara estranho....";
        }

    }

    if(opcao == 2){
        std::cout << "O vendedor te olha e pergunta: Pronto pra batalha?" << std::endl;
        
        std::cout << "1-Não\n2-Espada\n3-Adaga" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            std::cout << "Bela escolha!" << std::endl;

            if(p.creditos >= 200){
                std::cout << "Muitos cairão por essa lâmina!!" << std::endl;
                p.creditos = p.creditos - 200;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Você não merece este tesouro plebeu!!" << std::endl;
            }

        }else if(opcao == 3){
            std::cout << "Pelo menos dá para apontar um lápis" << std::endl;

            if(p.creditos >= 25){
                std::cout << "ok..." << std::endl;
                p.creditos = p.creditos - 25;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Saia daqui farrapo!!!" << std::endl;
            }
        }else{
            std::cout << "Vá embora!." << std::endl;
        }
    }
}

void faseDaDungeon(struct Personagem &p){
    //Escolha das missões
    int ponte = 0;
    int resposta = 0;
    int repetir ;
    unsigned  int menu = 0;
    unsigned int escolha = 0;
    
    while(escolha < 1 || escolha > 2){
    std::cout << "Depois de sair Você vê um quadro de missões, nele só tem 2 papeis. Deseja olhar eles? \n";
    std:: cout << "1-Sim\n2-Não";
    std::cin >> escolha;
    }


    
    if(escolha == 1){
        for( ; ;) {
    std::cout << "Digite 1-MISSÃO DE ALTO NIVEL\n 2-MISSÃO BAIXO NIVEL";


    std::cin >> escolha;
    std::cout << "--------------------------------";

       if(escolha == 1){
       std::cout << "MISSÃO DE ALTO NIVEL!!!"<<std::endl;
       std::cout << "RECOMPENSA DE 200 CRÉDITOS"<<std::endl;
       std::cout << "Objetivo:Matar todos os Esqueletos!"<<std::endl;
       std::cout << "Existe uma Dungeon dos Esqueletos de Schrödinger que precisa ser destruida antes que sejá tarde, eles são muito fortes então tomem cuidado ao tentar destruir o lugar\n"<<std::endl;
       std::cout << "Se desejar ir basta seguir pelo caminho das Árvores Mortas que está ao lado da entrada para a cidade.\n"<<std::endl;
   }
    else if(escolha == 2){
        std::cout << "MISSÃO DE BAIXO NIVEL -_-"<<std::endl;
        std::cout << "RECOMPENSA DE 70 CRÉDITOS"<<std::endl;
        std::cout << "Objetivo:Destruir todos os Slimes!"<<std::endl;
        std::cout << "Perto da cidade existem um campo aberto onde varios Slimes estão vivendo, eles não fazem mal a ninguém, mas estão sujando e assustando alguns moradores da cidade\n"<<std::endl;
        std::cout << "Eles são bem fraquinhos então são bem faceis de serem derrotados\n"<<std::endl;
        std::cout << "Caso aceite o caminho para o lugar é logo depois da saida da cidade.\n "<<std::endl;    
    }
        repetir = 0;
        std::cout << "Se você deseja ler a outra missão digite 2"<< std::endl;
        std::cin >> repetir;

        if(repetir == 1 ){
            break;
        }
   }    
   escolha = 0;

    std:: cout <<"Agora precisa decidir qual delas você escolhe?\n 1-Missão de Alto nivel\n 2-Missão de baixo nivel"<< std::endl;
    std:: cin >> escolha;

    if(escolha == 1){
        escolha = 0;
        std::cout << "ok então você realmente é ganancioso hehe\n"<< std::endl;
        std::cout << "Então você volta para o começo da cidade e desce o caminho das Árvores Mortas e vai percebendo que o ambiente está ficando estranho e cinza\n"<< std::endl;
        std::cout << "Depois de um bom tempo andando você chega em uma dungeon bem grande e você vê uma porta\n deseja bater?"<< std::endl;
        std::cout << "1 - sim 2 - não"<< std::endl;
        std::cin >> escolha;
        if(escolha == 1){
            std::cout << "Você vai chegando perto e o clima fica cada vez mais tenso\n" << std::endl;
            std::cout << "Você bate..."<< std::endl;
            std::cout << "..."<< std::endl;
            escolha = 0;
            std::cout <<" POW POW os esqueletos derrubam a porta e vão para cima de você"<< std::endl;
            std::cout << "1 - correr\n 2- lutar?\n"<< std::endl;
            std::cin >> escolha;
            switch (escolha)
            {
            case 1:
            std::cout << "Você vira e tenta correr, porém uma flecha te acerta bem no peito." << std::endl;
            std::cout << "Você morreu de hemorragia kkkk"<< std::endl;
            std::cout << "Tente novamente!!"<< std::endl;
            return;
            case 2:
            std::cout << "Lutar? kkkkk como que luta sem espada?"<< std::endl;
            std::cout << "Os esqueletos te cercam e enfiam as espadas em você"<<std::endl;
            std::cout << "Você morreu kkkkk -_-"<<std::endl;
            std::cout << "Tente novamente!!"<< std::endl;
            return;
            
            default:
            std::cout << "Você fica parado e eles te cercam e te matam a espadadas"<< std::endl;
            std::cout << "Você morreu kkkkkkkk -_-"<<std::endl;
            return;

            }
        }if(escolha == 2){
            escolha = 0;
            std:: cout << "De dentro da porta você ouve uma voz"<< std::endl;
            std::cout << "Responda uma pergunta, acertando poderá entrar errando morrerá. "<< std::endl;
            std:: cout << "Você reposnde? 1-sim 2-não";
            std::cin >> escolha;
            if(escolha == 1){
                std:: cout << "A pergunta é com quantos paus se fazem uma canoa?" << std::endl;
                std:: cout << "1- Um só\n 2-300\n 3-Não sei nunca fiz uma canoa" << std::endl;
                std::cin >> resposta;
                switch (resposta)
                {
                case 1:
                std::cout << "Errado\n você recebe um flechada e morre"<<std::endl;
                    break;
                case 2:
                std::cout << "Errado\n você recebe 2 flechas no peito e morre" << std::endl;
                 break;
                 case 3 :
                 std::cout << "Ta ok você acertou\n agora você precisará do código para entrar: 1234"<< std::endl;
                 break;
                
                default:
                std::cout << "falou errado perdeu a vez"<< std::endl;
                    break;
                }

                do{
                    std::cout << "Qual o código?" << std::endl;
                    std::cin >> resposta;

                    ponte++;

                        
                }while(resposta != 1234 && ponte <= 3);
            }
            if(escolha == 2){
                std::cout << "Já que você não quer responder começa o game de novo ai"<<std::endl;
                //p.energia = p.energia - p.energia;
            }
        }

    }

}if(escolha == 2){
    std::cout << "Poxa não quer ler as missão fica dificil, só de raiva vai ter que começar de novo"<<std::endl;
}

    }
   

int main(int argc, char** argv)
{
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();

    std::cout << "Você recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);

    faseDaCidade(j);

    mostraStatusDoJogador(j);

    faseDaDungeon(j);
}

