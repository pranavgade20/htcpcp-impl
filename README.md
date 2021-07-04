# htcpcp-impl

## Usage
use cmake o build.

To start brewing coffee:
` curl -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'start\r\n' localhost:8080`

To stop brewing coffee:
` curl -X POST -H "Accept-Additions: milk-type=Cream; syrup-type=Almond; alcohol-type=Whisky; milk-type=Skim;" --data $'stop\r\n' localhost:8080`

## TODO
1. Write ctests
