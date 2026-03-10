#include <cstddef>
void square (const float* in, float* out, size_t s){
 for (size_t i=0;i<s;i++)
 out[i]=in[i]*in[i];
}


// desarrollar main de cpu
int main(){
    size_t size =64;
    size_t size_bytes= size *sizeof(float); // tenemos una constante para el número de tamaño
    float  *in= (float*)malloc(size_bytes); //Mucho mejor así
    float*out =(float*)malloc(size * sizeof(*out)); // rrealizando esta multi lo que hacemos es que en vez de float cogemos el tamaño de una variable q es float
   for (int i =0; i<size; ++i){
        in[]= rand(); 
   }
   square(in, out,size);
   for (int i =0; i<size; i++){
        print(out[i]);
   }


}


/// PARA PASAR DE CPU A GPU
// duda q es lo que pasas resultado o proceso

int main(){
    size_t size =64;
    size_t size_bytes= size *sizeof(float); // tenemos una constante para el número de tamaño
    float  *in= (float*)malloc(size_bytes); //Mucho mejor así
    float*out =(float*)malloc(size * sizeof(*out)); // rrealizando esta multi lo que hacemos es que en vez de float cogemos el tamaño de una variable q es float
   // Implementamos los cambios para poder pasar de cpu a gpu
   float *device_in;
   float *devide_out;
   cudaMalloc(&device_in, size_bytes);
   cudaMalloc(&device_out, size_bytes);
   
    for (int i =0; i<size; ++i){
        in[]= rand(); 
        // se ejecuta en la gpu
        cudaMemcpy(device_in, in,size_bytes, cudaMemcpyHostToDevice);
   }
   square(in, out,size);
   cudaMemcpy(devide_out,out,size_bytes, cudaMemcpyDeviceToHost)
   for (int i =0; i<size; i++){
        print(out[i]);
   }


}