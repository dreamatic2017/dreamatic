__kernel void hello(__global char* string)
{
string[0] = 'H';
string[1] = 'e';
string[2] = 'l';
string[3] = 'l';
string[4] = 'o';
string[5] = '!';
string[6] = ' ';
string[7] = 'M';
string[8] = 'o';
string[9] = 'w';
string[10] = 'o';
string[11] = 'w';
string[12] = '!';
string[13] = '\0';
}