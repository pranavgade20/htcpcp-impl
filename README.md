# htcpcp-impl

## Usage
use cmake o build.

To start brewing coffee:
` curl -i -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'start\r\n' localhost:8080`

To stop brewing coffee:
` curl -i -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'stop\r\n' localhost:8080`

## Contents
1. Introduction
2. Goal
3. Tech-Stack/Tooling
4. Project Structure
   - Pot
   - Derived Pots
   - Cup/Additions
   - Request/Response
   - Networking
   - Docker/k8s
5. Processing
6. Results
7. Future Scope of the Project
