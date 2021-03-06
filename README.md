# htcpcp-impl
This project implements a client and server conforming to RFC2324 HTCPCP/1.0 (Hyper Text Coffee Pot Control Protocol).

The RFC was originally intended to be an April Fools' joke, but Error 418 (I'm a teapot) has gained popularity as a classic easter egg in developer circles, so we decided to implement a server and a client conforming to this protocol to communicate. 

P.S.: This branch(`master`) has been updated after the submission deadline. To see our final submission, please see https://github.com/pranavgade20/htcpcp-impl/tree/frozen

## Documentation
You can find detailed doxygen generated documentation here: [htcpcp-implementation-docs.netlify.app](https://htcpcp-implementation-docs.netlify.app/)

## Building and Usage
1. Use cmake to build.
2. `docker build --tag htcpcp .` to build the docker image
3. `kubectl apply -f k8s.yml` to deploy to your kubernetes cluster
4. Alternatively, run the built binary `htcpcp` locally with: `./htcpcp 8080 coffeepot`

5. To start brewing coffee:```curl -i -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'start\r\n' localhost:8080```
6. To stop brewing and get your coffee:```curl -i -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'stop\r\n' localhost:8080```

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

