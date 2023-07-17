
#ifndef MyValue_H
#define MyValue_H
class MyMatrix;
class MyValue
{
private:
	MyMatrix *matrix; // the matrix that the value belong to
	unsigned int row; //the row of the value
	unsigned int column; //the column of the value
public:
	MyValue(MyMatrix* mat = 0,unsigned int rows = 0, unsigned int col = 0); // multi-arguments constructor
	MyValue(const MyValue&); // copy constructor
	~MyValue(); //destructor
	float the_value() const; //use the row and column to output the value
	void output() const; //output information of ¡§this¡¨ object
};
#endif MyValue_H
