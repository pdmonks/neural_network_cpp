#include <iostream>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

vector<vector<float>> hidden_layer_weights;
vector<vector<float>> output_layer_weights;
vector<float> single_vector;
vector<float> hidden_layer_outputs;

void printNestedVector(vector<vector<float> > nested_vector)
{
    cout << "[\n";

    // nested_vector`s iterator(same type as nested_vector)
    // to iterate the nested_vector
    vector<vector<float> >::iterator nested_vector_itr;

    // Print the nested_vector
    for (nested_vector_itr = nested_vector.begin();
        nested_vector_itr != nested_vector.end();
        ++nested_vector_itr
        ) {

        cout << "  [";

        // normal_vector`s iterator(same type as temp_vector)
        // to iterate the normal_vector
        vector<float>::iterator single_vector_itr;

        // pointer of each vector one by one in nested vector
        // as loop goes on
        vector<float>& single_vector_pointer = *nested_vector_itr;

        for (single_vector_itr = single_vector_pointer.begin();
            single_vector_itr != single_vector_pointer.end();
            single_vector_itr++) {
            cout << " " << *single_vector_itr << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}


vector<vector<float>> initialize_hidden_layer(int n_inputs, int n_hidden)
{
    cout << "Hidden layer weights:" << endl;
    //vector<vector<float>> hidden_layer_weights;

    for(int i=0; i < n_hidden; i++)
    {
        for(int j=0; j < n_inputs + 1; j++)
        {
            float random_float = ((float)rand()) / (float)RAND_MAX;
            single_vector.push_back(random_float);
        }
        hidden_layer_weights.push_back(single_vector);

        // delete all elements from single_vector
        single_vector.erase(single_vector.begin(), single_vector.end());
    }

    // initialise hidden layer outputs as same size as number of hidden layers
    for (int i=0; i < n_hidden; i++)
    {
        hidden_layer_outputs.push_back(0);
    }

    return hidden_layer_weights;
}

vector<vector<float>> initialize_output_layer(int n_hidden, int n_outputs)
{
    cout << "Output layer weights:" << endl;
    //vector<vector<float>> output_layer_weights;

    for(int i=0; i < n_outputs; i++)
    {
        for(int j=0; j < n_hidden + 1; j++)
        {
            float random_float = ((float)rand()) / (float)RAND_MAX;
            single_vector.push_back(random_float);
        }
        output_layer_weights.push_back(single_vector);

        // delete all elements from single_vector
        single_vector.erase(single_vector.begin(), single_vector.end());
    }

    return output_layer_weights;
}

void initialize_network(int n_inputs, int n_hidden, int n_outputs)
{
    hidden_layer_weights = initialize_hidden_layer(n_inputs, n_hidden);
    printNestedVector(hidden_layer_weights);

    output_layer_weights = initialize_output_layer(n_hidden, n_outputs);
    printNestedVector(output_layer_weights);
}

// types may change from vector to vector of vectors
float activate(vector<float> weights, vector<float> inputs)
{
    float activation = weights.back();
    for (int i=0; i < weights.size() - 1; i++)
    {
        activation += weights[i] * inputs[i];
    }
    return activation;
}

float transfer(float activation)
{
    return 1.0 / (1.0 + exp(-activation));
}

//vector<float> forward_propagate(vector<vector<float>> hidden_layer_weights,
//    vector<vector<float>> output_layer_weights, vector<float> row)
vector<float> forward_propagate(vector<float> row)
{
    vector<float> inputs = row;

    // first layer is hidden layer
    vector<float> new_inputs;
    for(int i=0; i < hidden_layer_weights.size() - 1; i++)
    {
        float activation = activate(hidden_layer_weights[i], inputs);
        hidden_layer_outputs[i] = transfer(activation);
        new_inputs.push_back(hidden_layer_outputs[i]);
    }
    inputs = new_inputs;
    return inputs;
}

float transfer_derivative(float output)
{
    return output * (1.0 - output);
}

void backward_propagate_error(vector<int> expected)
{
    // do output layer first
    //for (int i=0; i < output_layer_weights.size(); i++)
    //{
    //    vector<float> layer = output_layer_weights[i];
    //    list<float> errors = {};
    //    if (i != output_layer_weights.size() - 1)
    //    {
    //        for (int j=0; j < output_layer_weights.size(); j++)
    //        {
    //            float error = 0.0;
    //            for (int k=0; k < output_layer_weights[i + 1].size(); k++)
    //            {
    //                error += 
    //            }
    //        }
    //    }
    //
    //}
}

int main()
{
    initialize_network(2, 3, 2);

    //vector<int> test1 = {1,2,3};
    //cout << test1[2] << endl;

    //vector<vector<int>> test2 = {{1,2,3}, {4,5,6}};
    //cout << test2[1][2] << endl;

    //vector<vector<vector<int>>> test3 = {{{1,2,3}, {4,5,6}}, {{7,8,9}, {10,11,12}}};
    //cout << test3[1][1][2] << endl;

    hidden_layer_weights.push_back({0.13436424411240122, 0.8474337369372327, 0.763774618976614});
    output_layer_weights.push_back({0.2550690257394217, 0.49543508709194095});
    output_layer_weights.push_back({0.4494910647887381, 0.651592972722763});
    vector<float> row = {1, 0, NULL};
    vector<float> output = forward_propagate(row);

    cout << output[0] << endl;
    cout << output[1] << endl;

    return 0;
}