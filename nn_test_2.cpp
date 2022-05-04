#include <iostream>
#include <list>
#include <math.h>
#include <iterator>
#include <vector>

using namespace std;


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


void printNestedNestedVector(vector<vector<vector<float>>> nested_nested_vector)
{
    cout << "[\n";
    vector<vector<vector<float>>>::iterator nested_nested_vector_itr;

    for (nested_nested_vector_itr = nested_nested_vector.begin();
        nested_nested_vector_itr != nested_nested_vector.end();
        ++nested_nested_vector_itr
        ) {

        cout << "[\n";

        // nested_vector`s iterator(same type as nested_vector)
        // to iterate the nested_vector
        vector<vector<float> >::iterator nested_vector_itr;

        vector<vector<float>>& nested_vector_pointer = *nested_nested_vector_itr;

        // Print the nested_vector
        for (nested_vector_itr = nested_vector_pointer.begin();
            nested_vector_itr != nested_vector_pointer.end();
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
    cout << "]\n";
}


void printNestedNestedNestedVector(vector<vector<vector<vector<float>>>> nested_nested_nested_vector)
{
    cout << "[\n";
    vector<vector<vector<vector<float>>>>::iterator nested_nested_nested_vector_itr;

    for (nested_nested_nested_vector_itr = nested_nested_nested_vector.begin();
        nested_nested_nested_vector_itr != nested_nested_nested_vector.end();
        ++ nested_nested_nested_vector_itr
    ) {

        cout << "[\n";
        vector<vector<vector<float>>>::iterator nested_nested_vector_itr;

        vector<vector<vector<float>>>& nested_nested_vector_pointer = *nested_nested_nested_vector_itr;

        for (nested_nested_vector_itr = nested_nested_vector_pointer.begin();
            nested_nested_vector_itr != nested_nested_vector_pointer.end();
            ++nested_nested_vector_itr
            ) {

            cout << "[\n";

            // nested_vector`s iterator(same type as nested_vector)
            // to iterate the nested_vector
            vector<vector<float> >::iterator nested_vector_itr;

            vector<vector<float>>& nested_vector_pointer = *nested_nested_vector_itr;

            // Print the nested_vector
            for (nested_vector_itr = nested_vector_pointer.begin();
                nested_vector_itr != nested_vector_pointer.end();
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
        cout << "]\n";
    }
    cout << "]\n";
}


// initialise a network
vector<vector<vector<vector<float>>>> initialize_network(int n_inputs, int n_hidden, int n_outputs)
{
    cout << "Initialize Network\n";

    vector<vector<vector<vector<float>>>> network;

    vector<float> output_data = {0};
    vector<float> weight_data;
    vector<float> delta_data = {0};

    vector<vector<float>> hidden;
    vector<vector<vector<float>>> hidden_layer;

    for (int i=0; i < n_hidden; i++)
    {
        hidden.push_back(output_data);
        for (int j=0; j < n_inputs + 1; j++)
        {
            float random_float = ((float)rand()) / (float)RAND_MAX;
            weight_data.push_back(random_float);
        }
        hidden.push_back(weight_data);
        hidden.push_back(delta_data);
        // delete all elements from weight vector
        weight_data.erase(weight_data.begin(), weight_data.end());
        hidden_layer.push_back(hidden);
        // delete all elements from hidden vector
        hidden.erase(hidden.begin(), hidden.end());
    }
    //printNestedNestedVector(hidden_layer);

    vector<vector<float>> output;
    vector<vector<vector<float>>> output_layer;

    for (int i=0; i < n_outputs; i++)
    {
        output.push_back(output_data);
        for (int j=0; j < n_hidden + 1; j++)
        {
            float random_float = ((float)rand()) / (float)RAND_MAX;
            weight_data.push_back(random_float);
        }
        output.push_back(weight_data);
        output.push_back(delta_data);
        // delete all elements from weight vector
        weight_data.erase(weight_data.begin(), weight_data.end());
        output_layer.push_back(output);
        // delete all elements from output vector
        output.erase(output.begin(), output.end());
    }
    //printNestedNestedVector(output_layer);

    network.push_back(hidden_layer);
    network.push_back(output_layer);
    //printNestedNestedNestedVector(network);

    return network;
}


// calculate neuron activation for an input
float activate(vector<float> weights, vector<float> inputs)
{
    float activation = weights.back();
    for (int i=0; i < weights.size() - 1; i++)
    {
        activation += weights[i] * inputs[i];
    }
    return activation;
}


// transfer neuron activation
float transfer(float activation)
{
    return 1.0 / (1.0 + exp(-activation));
}


// forward propagate input to a network output
vector<float> forward_propagate(vector<vector<vector<vector<float>>>> network, vector<float> row)
{
    vector<float> inputs = row;

    for (int i=0; i < network.size(); i++)
    {
        vector<float> new_inputs;
        vector<vector<vector<float>>> layer = network[i];
        for (int j=0; j < layer.size(); j++)
        {
            float activation = activate(layer[j][1], inputs);
            layer[j][0][0] = transfer(activation);
            new_inputs.push_back(layer[j][0][0]);
        }
        inputs = new_inputs;
    }
    
    return inputs;
}


// calculate the derivative of a neuron output
float transfer_derivative(float output)
{
    return output * (1.0 - output);
}


// backpropagate error and store in neurons
vector<vector<vector<vector<float>>>> backward_propagate_error(vector<vector<vector<vector<float>>>> network, vector<float> expected)
{
    // returns a network instead of updating existing network, think because of memory allocation.
    // will amend this back to a void method when i know more about pointers, etc.
    
    //cout << "network size: " << network.size() << endl;
    for (int i = network.size() - 1; i >= 0; i--)
    {
        //cout << "iteration: " << i << endl;
        vector<vector<vector<float>>> layer = network[i];
        //float test = network[i][0][0][0];
        //cout << "test: " << test << endl;
        vector<float> errors;

        if (i != network.size() - 1)
        {
            //cout << "i != network.size()" << endl;
            for (int j=0; j < layer.size(); j++)
            {
                //cout << "layer size: " << layer.size() << endl;
                //cout << "j = " << j << endl;
                float error = 0.0;
                
                vector<vector<vector<float>>> next_layer = network[i + 1];
                
                for (int k=0; k < next_layer.size(); k++)
                {
                    error += (next_layer[k][1][j] * next_layer[k][2][0]);
                    //cout << next_layer[k][1][j] << endl;
                    //cout << next_layer[k][2][0] << endl;
                    //cout << "error: " << error << endl;
                }
                errors.push_back(error);
            }
        }
        else
        {
            for (int j=0; j < layer.size(); j++)
            {
                //cout << "neuron: " << j << endl;
                vector<vector<float>> neuron = layer[j];
                errors.push_back(neuron[0][0] - expected[j]);
                //cout << neuron[0][0] << endl;
                //cout << expected[j] << endl;
            }
        }
        for (int j=0; j < layer.size(); j++)
        {
            vector<vector<float>> neuron = layer[j];
            //cout << "-----" << endl;
            //cout << "delta info: " << neuron[2][0] << endl;
            //cout << "error: " << errors[j] << endl;
            //cout << "td: " << neuron[0][0] << endl;
            // update the network rather than the neuron - again due to memory allocation i think
            //neuron[2][0] = errors[j] * transfer_derivative(neuron[0][0]);
            network[i][j][2][0] = errors[j] * transfer_derivative(neuron[0][0]);
            //cout << "delta: " << neuron[2][0] << endl;
            //cout << "delta: " << network[i][j][2][0] << endl;
        }
    }

    return network;
}


vector<vector<vector<vector<float>>>> update_weights(vector<vector<vector<vector<float>>>> network, vector<float> row, float l_rate)
{
    for (int i=0; i < network.size(); i++)
    {
        vector<float> inputs = row;
        inputs.pop_back();
        for (int x = 0; x < inputs.size(); ++x)
            cout << inputs[x] << endl;

        if (i != 0)
        {
            inputs = {};
            for (int neuron=0; neuron < network[i - 1].size(); neuron++)
            {
                inputs.push_back(network[i - 1][neuron][0][0]); 
            }
        }
        //for (int size=0; size < inputs.size(); size++)
        //{
        //    cout << inputs[size] << endl;
        //}
        for (int neuron=0; neuron < network[i].size(); neuron++)
        {
            for (int j=0; j < inputs.size(); j++)
            {
                network[i][neuron][1][j] -= l_rate * network[i][neuron][2][0] * inputs[j];
            }
            network[i][neuron][1].back() -= l_rate * network[i][neuron][2][0];
        }
    }
    return network;
}


vector<vector<vector<vector<float>>>> train_network(vector<vector<vector<vector<float>>>> network,
    vector<vector<float>> train, float l_rate, int n_epoch, int n_outputs)
{
    for (int epoch=0; epoch < n_epoch; epoch++)
    {
        float sum_error = 0.0;
        for (int row=0; row < train.size(); row++)
        {
            vector<float> outputs = forward_propagate(network, train[row]);
            vector<float> expected;
            for (int output=0; output < n_outputs; output++)
            {
                expected.push_back(0);
            }
            expected[train[row].size()] = 1;    // expected[row[-1]] = 1
            for (int exp=0; exp < expected.size(); exp++)
            {
                sum_error += pow((expected[exp] - outputs[exp]), 2);    // (expected[i] - outputs[i]) ** 2
            }
            network = backward_propagate_error(network, expected);
            network = update_weights(network, train[row], l_rate);
        }
        cout << ">epoch =  " << epoch << "l_rate = " << l_rate << "error = " << sum_error << endl; 
    }
    return network;
}


int main()
{
    //vector<float> output_0 = {0};
    //vector<float> weights_0 = {0,1,2};
    //vector<float> delta_0 = {0};
    //vector<vector<float>> hidden_1 = {output_0, weights_0, delta_0};
    //cout << hidden_1[1][1] << endl;
    //printNestedVector(hidden_1);

    //vector<vector<vector<float>>> hidden_layer;
    //hidden_layer.push_back(hidden_1);
    //printNestedNestedVector(hidden_layer);    

    //vector<float> output_1 = {1};
    //vector<float> weights_1 = {3,4,5};
    //vector<float> delta_1 = {1};
    //vector<vector<float>> outputs_1 = {output_1, weights_1, delta_1};
    //cout << outputs_1[1][1] << endl;
    //printNestedVector(outputs_1);

    //vector<float> output_2 = {2};
    //vector<float> weights_2 = {6,7,8};
    //vector<float> delta_2 = {2};
    //vector<vector<float>> outputs_2 = {output_2, weights_2, delta_2};
    //cout << outputs_2[1][1] << endl;
    //printNestedVector(outputs_2);

    //vector<vector<vector<float>>> output_layer_test;
    //output_layer_test.push_back(outputs_1);
    //output_layer_test.push_back(outputs_2);
    //printNestedNestedVector(output_layer_test);

    //vector<vector<vector<vector<float>>>> network;
    //network.push_back(hidden_layer);
    //network.push_back(output_layer);
    //printNestedNestedNestedVector(network);

    vector<vector<vector<vector<float>>>> network = initialize_network(2,1,2);
    //cout << network.size() << endl;

    // test forward propagation
    vector<vector<vector<vector<float>>>> network_test
    = {{{{0}, {0.13436424411240122, 0.8474337369372327, 0.763774618976614}, {0}}},{{{0},{0.2550690257394217, 0.49543508709194095},{0}},{{0},{0.4494910647887381, 0.651592972722763},{0}} }};
    //printNestedNestedNestedVector(network_test);
    vector<float> row = {1, 0, NULL};
    vector<float> output = forward_propagate(network_test, row);
    cout << output[0] << endl;
    cout << output[1] << endl;

    // test backpropagation of error
    vector<vector<vector<vector<float>>>> network_test_2
    = {{{{0.7105668883115941}, {0.13436424411240122, 0.8474337369372327, 0.763774618976614}, {0}}},{{{0.6213859615555266},{0.2550690257394217, 0.49543508709194095},{0}},{{0.6573693455986976},{0.4494910647887381, 0.651592972722763},{0}} }};
    vector<float> expected = {0, 1};
    // send network rather than updating network as in python version
    network_test_2 = backward_propagate_error(network_test_2, expected);
    printNestedNestedNestedVector(network_test_2);

    // test training backprop algorithm
    //seed(1)
    //srand(1);
    //vector<vector<float>> dataset = {{2.7810836,2.550537003,0},
	//{1.465489372,2.362125076,0},
	//{3.396561688,4.400293529,0},
	//{1.38807019,1.850220317,0},
	//{3.06407232,3.005305973,0},
	//{7.627531214,2.759262235,1},
	//{5.332441248,2.088626775,1},
	//{6.922596716,1.77106367,1},
	//{8.675418651,-0.242068655,1},
	//{7.673756466,3.508563011,1}};
    //int n_inputs = dataset[0].size() - 1;
    //cout << "inputs: " << n_inputs << endl;
    ////n_outputs = len(set([row[-1] for row in dataset]))
    //int n_outputs = dataset[0].size() - 1;
    //cout << "outputs: " << n_outputs << endl;
    //vector<vector<vector<vector<float>>>> network_test_3 = initialize_network(n_inputs, 2, n_outputs);
    //printNestedNestedNestedVector(network_test_3);
    //network_test_3 = train_network(network_test_3, dataset, 0.5, 20, n_outputs);
    //printNestedNestedNestedVector(network_test_3);

}

