#include <stdio.h>
#include <cstdlib>
#include <cmath>
struct neuron {
        FILE * weights;
};
struct floatArr {
        float arr[100];
};
class network {
        public:
                neuron * layer[100];
                neuron * writeWeights(int weight, char fname[]) {
                        neuron * output = (neuron*)malloc(sizeof(neuron*));
                        FILE * w = fopen(fname, "w+");
                        fprintf(w, "%d", weight);
                        output->weights = w;
                        return output;
                }
                void init() {
                        for (int i = 0; i <= 100; i++) {
                                char fname[100];
                                sprintf(fname, "%d.w.ai", i);
                                layer[i] = writeWeights(0, fname);
                        }
                }
                floatArr runFirstLayer(int input) {
                        floatArr output;
                        for (int i = 0; i <= 100; i++) {
                                float w;
                                fscanf(layer[i]->weights, "%f", &w);
                                output.arr[i] = sine(w * input + i);
                                if (output.arr[i] <= 0.25) {
                                        output.arr[i] = 0.25;
                                };
                                for (int j = 0; j <= 100; i++) {
                                        w = w * w;
                                }
                                w = w + output.arr[i];
                                w = w / 101;
                                fprintf(layer[i]->weights, "%f", w);
                        }
                        return output;

                }
};
int main() {
        network * n = (network*)malloc(2048);
        n->init();
        floatArr out = n->runFirstLayer(10);
        for (int i = 0; i <= 100; i++) {
                printf("%f", out.arr[i]);
        }
        for (int i = 0; i <= 100; i++) {
                fclose(n->layer[i]->weights);
        }
        free(n);
        printf("%f", sine(10));
        return 0;
};
