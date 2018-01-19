#include "main.hpp"

int main(int argc, char* argv[]) {
    if(argc > 1) {
        int seed;
        
        try {
            seed = std::stoi(argv[1]);
        } catch(...) {
            // Ignore all errors
            seed = 0;
        }
        
        randomizeWeights(s * s, W, seed);
    }
    
    size_t oldScore;
    size_t score;
    size_t t = 0;
    
	hexDumpMemory(W, s*s);
	std::cout << "Training:\t" << s << std::endl;
	std::cout << "Count:\t\t" << sizeMobyDick - 1 << std::endl;

    score = calculateScore( s, w, S );
    
	std::cout << "t = 0:\t\t" << score << std::endl;

	do {
		train( s, w, W, S );
		saveWeights( std::to_string(s), s, W );
        
        oldScore = score;
        score = calculateScore( s, w, S );
        
		std::cout << "t = " << ++t << ":\t\t" << score << std::endl;
	} while ( oldScore != score );
}

void randomizeWeights( const size_t weightsSize, uint8_t* weights, const uint8_t seed ) {
    srand(seed);
    
    for(size_t i = 0; i < weightsSize; ++i) {
        weights[i] = ((uint8_t) rand()) & 0x7F;
    }
}
