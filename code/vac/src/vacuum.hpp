#ifndef VAC_HPP
#define VAC_HPP

#include <SQuIDS/SQuIDS.h>

// task 1: Declare vacuum class publically derived from squids::SQuIDS class
/// Hint 1: Should have a private members storing mass squared diffs in a SU_vector
/// Hint 2: Should have two public members storing SU_vector projectors for B0 and B1 (three each)
/// Hint 3: Needed member functions: default constructor, initializing constructor, init function
/// H0 operator and a function returning the probabilities for given flavor index
class vacuum : public squids::SQuIDS
{
    private:
    squids::SU_vector DM2;
    
    public:
    squids::SU_vector *proj0;
    squids::SU_vector *proj1;

    // member functions
    vacuum();
    vacuum(unsigned int nbins, unsigned int nflavor, double E0, double E1);
    void init(unsigned int nbins, unsigned int nflavor, double E0, double E1);
    squids::SU_vector H0(double E, unsigned int irho) const;
    double GetProb(int, double);
    ~vacuum();
};

#endif
