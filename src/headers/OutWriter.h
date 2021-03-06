// Author: Aliaksei Mikhailiuk, 2017.

#ifndef OUTWRITER_H
#define OUTWRITER_H

#include <fstream> 
#include <iostream> 
#include <iostream>
#include <omp.h>
#include <ctime>
#include <string.h> 
#include <time.h>
#include <random>
#include <sys/stat.h>

#include "TrainingAlgorithm.h"
#include "NeuralNetwork.h"

/*! \class OutWriter
    \brief Class responsible for ouput folder and its contents

    Writes out data collected by neural network
*/
class OutWriter{

	private:
        //! Name of the folder to write in
        std::string folderName;

	public:

        //! Function which is called from the main. 
        // \param NeuralNetwork
        // \param Training algorithm
        // \param Time
        int write(NeuralNetwork *,TrainingAlgorithm *,double time, std::string mark);

        //! Function writes out learning rate versus iteration (learning rate changes if annealing is used)
        int writeLearningRate(TrainingAlgorithm *algorithm);

        //! Function to generate a folder name.
        int getFolderName();

        //! Funtion to write the training error (loss function vs iteration)
        int writeErrorTrain(TrainingAlgorithm *algorithm);

        //! Funtion to write the test error (loss function vs iteration)
        int writeErrorValidation(TrainingAlgorithm *algorithm);

        int writeRatio(TrainingAlgorithm *algorithm);

        //! Funtion to write the weights
        int writeWeights(NeuralNetwork *neuralNetwork,TrainingAlgorithm *algorithm);

        //! Function writes summary of the time.
        int writeTimeInfo(NeuralNetwork *neuralNetwork,TrainingAlgorithm *algorithm, double time);
                
        int writeStats (NeuralNetwork *neuralNetwork,TrainingAlgorithm *algorithm);
                
};


#endif
