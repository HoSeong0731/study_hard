#ifndef RESULT_H
#define RESULT_H

enum Result {
    Success = 0,

    InvalidAlgorithmName = 001,
    InvalidOptionName = 003,
    FaildtoUpdatePath = 005,
    
    CommandFileNotExist = 100,
    LoadFileNotExist = 101,

    VertexKeyNotExist = 200,
    InvalidVertexKey = 201,
    GraphNotExist = 202,
    InvalidAlgorithm = 203,
    NegativeCycleDetected = 204,

    NonDefinedCommand = 300,

    EqualRabin = 400,
    NotEqualRabin = 401,
};

#endif