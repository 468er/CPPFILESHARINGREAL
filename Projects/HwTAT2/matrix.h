// Name:
// Student Number:
// Date:

const int MAXROWS = 2;
const int MAXCOLS = 3;

template<typename T>
class Matrix
{
  private:
   T doubleArray[MAXROWS][MAXCOLS];
   int rows;
   int cols;

  public:
   // Constructor
    Matrix();  // Set rows to MAXROWS and cols to MAXCOLS
	            // Initialize all the values of doubleArray to zero
    
   // Getter Functions
   void printMatrix(); 

   // Setter Functions
    void setMatrix(T [][MAXCOLS]); // Set the doubleArray to what is sent
    void addMatrix(T [][MAXCOLS]); // Add an array to doubleArray
    void addMatrix(Matrix otherMatrix); // Add a Matrix to doubleArray

   // destructor not needed
};