void faseDaDungeon(struct Personagem &p){
    //Escolha das missões
    int resposta = 0;
    int repetir ;
    unsigned  int menu = 0;
    unsigned int escolha = 0;
    
    while(escolha < 1 || escolha > 2){
    std::cout << "Depois de sair Você vê um quadro de missões, nele só tem 2 papeis. Deseja olhar eles? \n";
    std:: cout << "1-Sim\n2-Não";
    std::cin >> escolha;
    }


    

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
            break;
            case 2:
            std::cout << "Lutar? kkkkk como que luta sem espada?"<< std::endl;
            std::cout << "Os esqueletos te cercam e enfiam as espadas em você"<<std::endl;
            std::cout << "Você morreu kkkkk -_-"<<std::endl;
            std::cout << "Tente novamente!!"<< std::endl;
            break;
            
            default:
            std::cout << "Você fica parado e eles te cercam e te matam a espadadas"<< std::endl;
            std::cout << "Você morreu kkkkkkkk -_-"<<std::endl;
            
                break;
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
                 std::cout << "Ta ok você acertou\n a você precisará do código para entrar: 1234"<< std::endl;
                 break;
                
                default:
                std::cout << "falou errado perdeu a vez"<< std::endl;
                    break;
                }
            }
            if(escolha == 2){
                std::cout << "Já que você não quer responder começa o game de novo ai"<<std::endl;
                //p.energia = p.energia - p.energia;
            }
        }

    }

}