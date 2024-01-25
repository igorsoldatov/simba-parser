# simba-parser
Parser for SIMBA SPECTRA protocol

# build
cmake . -G Ninja -B build
cd build
ninja

# usage
ParserSimba.exe -p input.pcap -o output.json
