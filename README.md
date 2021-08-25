# Valuator
Compute the value of the expressions in XML files.

## Run
```
> Valuator.exe inputDir outputDir
```

## Build
Dependencies: 
* Boost must be installed for using XML parser.
* C++17 or newer is the C++ standard for using filesystem.
If you use Visual Studio Code, make sure c_cpp_properties.json and tasks.json reflect those dependencies.
    
You can modify the code and rebuild with command
```
> g++ -std=c++17 -IC:\MyLibs\boost_1_77_0 .\*ion.cpp .\Valuator.cpp .\main.cpp -o Valuator
```

## Variations 
### If you want to change the behaviors of existing operations: 
* Modify the classes Addition, Subtraction, Multiplication and Division.
* Update the unit tests in ExpressionTest.cpp

### If you want to create new operations:
* Create new classes like existing classes that inherit the class Expression.
* Create some unit tests in ExpressionTest.cpp

### If you want to change the format of the input/output files:
* Modify Valuator.cpp and main.cpp with your new structures/naming. 