# StringFormatter
## Intro
This is my own string formatting library. 

## Why don't other libs suitable?
Of course we can use boost::format, fmt::format, QString::format they all work in a similar scenario:
```c++
someformat("Hello %0%") % "World";
```
Or
```c++
someformat("Hello {0}", "World");
```
then this does not suit us, because there are no named variables <b>inside</b> some string. 

## What this string formatter do
My string formatter usess named variables inside our string, instead of numbers.
That is, based on the example above, we must adhere to the following. syntax:
```c++
cout << stringFormatter("Hello {:key}", std::pair<std::string, std::string>(":key", "value")) << endl;
cout << stringFormatter("a = {:a}", {":a", 10}) << endl;
```

This would be very convenient to use inside large projects, especially in conjunction with SQL, where different data in a row are often used in many places. And this line needs to be “built” somehow.

## Formatting syntax
1. Absolutely all variables inside a line must be wrapped in ```{}```
2. Also we should write ```:``` before the variable name.
Final example: ```{:some-key}```

## Example
![image](https://github.com/Ihavenonames2/StringFormatter/assets/115930939/3bbcbf29-2993-439c-ac7f-626118370bf1)

## How to use
1. Download the .cpp and the .h file
2. #include them into ur project
3. Enjoy
