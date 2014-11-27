BelemTur
========

Trabalho Final de Programação 2 - Aplicativo de turismo em Belém

Requisitos: 

Importante: Para cada item abaixo deve ser copiado trechos do código que cumprem o requisito e explicado, se não for aparente, o porquê o requisito é cumprido. Sejam bem explícitos. Deve ser indicado também o arquivo da classe em que está o trecho do código. Eu avaliarei o código do Github a partir desse documento para confirmá-lo e também para detectar possíveis erros. Quem não seguir o que está indicado aqui, não terá o projeto avaliado e perderá a atividade. 

Criar repositórios desde o início do desenvolvimento. Primeiro commit deve estar com todas as classes declaradas sem implementação.

Primeira versão do código completa dia 01 de dezembro.

Versão final do código dia 08 de dezembro.

No dia da apresentação deve ser mostrado o código rodando para vários casos de teste.

Será avaliado o quanto o projeto está elaborado. Trabalhos muito simples com métodos apenas mostrando mensagens, serão penalizados.

Requisitos de implementação para C++
Todas as classes concretas devem vir de classes abstratas. Pelo menos três hierarquias de classes. Uma das hierarquias deve ter três níveis. Exemplo: Personagem (abstract) >> Ciborgue (Abstract) >> Robocop; Class Arma (Abstract) >> Beretta93R
Em todas as classes: construtor de cópia, operatores<< e +=, e construtor default. Fazer o máximo de reaproveitamento de código usando static_cast 
Todas as hierarquias devem ter classes Concretas, e em uma das hierarquias, três classes Concretas relacionadas:  Exemplo Servico >> ServicoStream >> (Netflix, HBOStream, AmazonPrime, NowTv). Em uma pesquisa de 10 segundos: http://www.tomsguide.com/us/pictures-story/620-top-online-streaming-video.html
Atributos static e const static em todas as hierarquias de classe
Método static em todas as hierarquias de classe
Construtores em todas as classes, e três para todas as classes da hierarquia principal. Sempre validar os dados em todas as classes
 Vector em todas em todas as hierarquias de classe
ENUM na hierarquia principal
Usar o dynamic cast e typeid no main junto com as classes concretas. Para uma da classe concreta identificada, chamar um método dessa classe e fazer uma ação;
Usar o rand. Nota: deve ser usado conforme o contexto do projeto. Se for usado em um método genérico sem relação com a classe e apenas para cumpri-lo, esse requisito será desconsiderado. http://en.cppreference.com/w/cpp/numeric/random/rand
No main o usuário deve fazer entrada via teclado e interagir com a aplicação



Requisitos de implementação para Java
Todas as classes concretas devem vir de interfaces ou classes abstratas. Pelo menos três hierarquias de classes. Uma das hierarquias deve ter três níveis. Exemplo: Personagem >> Ciborgue >> Robocop; Class Arma (interface) >> Beretta93R
Ao menos três interfaces. A terceira interface deve ser uma interface que liga duas hierarquias como no exemplo da interface corredor (Figura 1).
Usar a interface Comparable e sobrescrever o método compareTo em pelo menos uma hierarquia
Sobrescrever equals para de Object
Todas as hierarquias devem ter classes Concretas, e em uma das hierarquias, três classes Concretas relacionadas:  Exemplo Servico >> ServicoStream >> (Netflix, HBOStream, AmazonPrime, NowTv). Em uma pesquisa de 10 segundos: http://www.tomsguide.com/us/pictures-story/620-top-online-streaming-video.html
Sempre usar o super para o máximo de reaproveitamento de código em todas as classes
Atributos static e const static em todas as hierarquias de classe
Método static em todas as hierarquias de classe
Três construtores para todas as classes, sendo um deles o construtor de cópia. Sempre validar os dados em todas as classes
ArrayList na hierarquia principal
ENUM na hierarquia principal
Usar o instanceof no main junto com as classes concretas. Para uma da classe concreta identificada, chamar um método dessa classe e fazer uma ação;
Dividir o projeto em pacotes
Sobrescrever para todas as classes o método toString
Usar a classe Random do pacote java.util (java.util.Random). Nota: deve ser usado conforme o contexto do projeto. Se for usado em um método genérico sem relação com a classe e apenas para cumpri-lo, esse requisito será desconsiderado.
No main o usuário deve fazer entrada via teclado e interagir com a aplicação. Opcional de bônus: pode ser usada a classe JOptionPane do pacote javax.swing. Vejam: showInputDialog e showMessageDialog.


Figura 1 – Interface Corredor conectando duas hierarquias de classe
