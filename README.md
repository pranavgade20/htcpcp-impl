# htcpcp-impl

## Usage
use cmake o build.

To start brewing coffee:
` curl -i -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'start\r\n' localhost:8080`

To stop brewing coffee:
` curl -i -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'stop\r\n' localhost:8080`

## Contents
1. [Introduction](https://github.com/pranavgade20/htcpcp-impl/wiki/1.-Introduction)
2. [Goal](https://github.com/pranavgade20/htcpcp-impl/wiki/2.-Goal)
3. [Tech-Stack/Tooling](https://github.com/pranavgade20/htcpcp-impl/wiki/3.-Tech-Stack-%5C-Tooling)
4. Project Structure
   - [Pot](https://github.com/pranavgade20/htcpcp-impl/wiki/4.1-Pot)
   - [Derived Pots](https://github.com/pranavgade20/htcpcp-impl/wiki/4.2-Derived-Pots)
   - [Cup/Additions](https://github.com/pranavgade20/htcpcp-impl/wiki/4.3-Cup-%5C--Additions)
   - [Request/Response](https://github.com/pranavgade20/htcpcp-impl/wiki/4.4-Request%5CResponse)
   - [Networking](https://github.com/pranavgade20/htcpcp-impl/wiki/4.5-Networking)
   - [Docker/k8s](https://github.com/pranavgade20/htcpcp-impl/wiki/4.6-Docker-K8s)
5. [Processing](https://github.com/pranavgade20/htcpcp-impl/wiki/5.-Processing)
6. [Results](https://github.com/pranavgade20/htcpcp-impl/wiki/6.-Results)
7. [Future Scope of the Project](https://github.com/pranavgade20/htcpcp-impl/wiki/7.-Future-Scope-of-the-project)
