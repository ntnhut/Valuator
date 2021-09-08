# Description
A folder contains a number of files. The files potentially can be huge (> 1GB). Each file holds a set of operations (addition, subtraction, multiplication and division) serialized to XML format. The operations may be simple (operands are constants) or complex (some of operands are expressions).

This application calculates the top-level operations from input files and store results in output files in XML format. 

## Run
```
> Valuator.exe inputDir outputDir
```

## Filenames
```
<output_filename>.xml = <input_filename>_result.xml
```
## Input format
data0001.xml
```xml
<expressions>
    <addition id="1">
        <item>2</item>
        <item>3</item>
        <item>4</item>
    </addition>
    <subtraction id="2">
        <minuend>3</minuend>
        <subtrahend>2</subtrahend>
    </subtraction>
    <multiplication id="3">
        <factor>5</factor>
        <factor>6</factor>
        <factor>8</factor>
    </multiplication>
    <division id="4">
        <dividend>54</dividend>
        <divisor>9</divisor>
    </division>
</expressions>
```

## Output format
data0001_result.xml
```xml
<expressions>
    <result id="1">9</result>
    <result id="2">1</result>
    <result id="3">240</result>
    <result id="4">6</result>    
</expressions>
```

## Complex expressions
To deal with complex expressions I consider any operand of an expression again an expression.

data0002.xml
```xml
<expressions>
    <addition id="10" complex="true">
        <item>2</item>
        <item>3</item>
        <item>  
            <subtraction>
                <minuend>7</minuend>
                <subtrahend>3</subtrahend>
            </subtraction>
        </item>
    </addition>
    <subtraction id="11">
        <minuend>3</minuend>
        <subtrahend>2</subtrahend>
    </subtraction>
    <multiplication id="12">
        <factor>5</factor>
        <factor>6</factor>
        <factor>8</factor>
    </multiplication>
    <multiplication id="13" complex="true">
        <factor>
            <addition>
                <item>2</item>
                <item>3</item>
                <item>4</item>
            </addition>
        </factor>
        <factor>6</factor>
        <factor>
            <multiplication>
                <factor>3</factor>
                <factor>4</factor>
                <factor>5</factor>
                <factor>10</factor>
                <factor>56</factor>
            </multiplication>
        </factor>
    </multiplication>
    <division id="14" complex="true">
        <dividend>54</dividend>
        <divisor>
            <addition>
                <item>3</item>
                <item>6</item>
            </addition>
        </divisor>
    </division>
</expressions>
```

data0002_result.xml
```xml
<expressions>
    <result id="10">9</result>
    <result id="11">1</result>
    <result id="12">240</result>
    <result id="13">1814400</result>
    <result id="14">6</result>
</expressions>
```

## Libraries used (dependencies)
* boost::property_tree (for XML parser)
* std::filesystem (C++17)

## Build
If you use Visual Studio Code, make sure c_cpp_properties.json and tasks.json reflect those dependencies.
    
You can modify the code and rebuild with command
```
> g++ -std=c++17 -IC:\MyLibs\boost_1_77_0 .\*ion.cpp .\Valuator.cpp .\main.cpp -o Valuator
```
## Variations 
This implementation is kept raw to easier explain how to solve the problem. For performance, scalability and usability, you need to change the code a bit. 

### If you want to change the behaviors of existing operations 
* Modify the classes Addition, Subtraction, Multiplication and Division.
* Update the unit tests in XXXTest.cpp

### If you want to create new operations (scalability)
* Create new classes like existing classes that inherit the class Expression.
* Create unit tests for each operations like the XXXTest.cpp.
* Use an unordered_map<string> to avoid multiple if-else in Valuator::createExpression()

### If you want to change the format of the input/output files
* Modify Valuator.cpp and main.cpp with your new structures/naming. 

### If you want to define what to handle in case of zero divisor
* Modify it in Division::value()