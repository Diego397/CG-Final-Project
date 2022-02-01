//
// Created by fbeze on 24/08/2019.
//

// #ifndef COMPUTACAOGRAFICA_ESFERA_HPP
// #define COMPUTACAOGRAFICA_ESFERA_HPP
// #include "biblioteca.hpp"
// #include "Objeto.hpp"
// class Esfera : public Objeto {
// public:
//     string nome;
//     float raio;
//     Ponto* centro;
//     Esfera(float pRaio, Ponto* pCentro, Material* material);
//     tuple<Ponto*,Objeto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
//     Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0);
//     void mudaCoodCamera(Camera *camera) override;
//     void mudaCoodMundo(Camera *camera) override;
//     Vetor calcularNormal(Ponto* p) override;
//     Objeto* aplicarEspelhamento(vector<Matriz> &pMatrizesTransf) override;
//     void aplicarTransformacao(vector<Matriz> &pMatrizesTransf) override;
//     Ponto* getCentro() override;
//     tuple<Ponto, Ponto> Limites() override;
// };


// #endif //COMPUTACAOGRAFICA_ESFERA_HPP
// Esfera::Esfera(float pRaio, Ponto* pCentro) : raio(pRaio), centro(pCentro), Objeto("Esfera",false, material)  {}

// tuple<Ponto*, Objeto*> Esfera::IntersecaoReta(Ponto* pP0, const Vetor &pV0){
//     //p_t_int eh o ponto dado o t_int
//     Ponto* p_t_int1 = nullptr;
//     Ponto* p_t_int2 = nullptr;
//     double t_int1, t_int2;

//     // A*t_int² + B*t_int + C = 0

//     Vetor pV0N = biblioteca::NormalizaVetor(pV0);

//     // C0P0 eh o P0 - C0
//     Vetor C0P0 = biblioteca::SubtracaoPontos(*this->centro, *pP0);

//     // A = u*u
//     double produtoA = biblioteca::ProdutoEscalar(pV0N,pV0N);

//     // B = 2 * (P0 - C0) * u
//     double produtoB = biblioteca::ProdutoEscalar(C0P0,pV0N);

//     // C = (P0 - C0) * (P0 - C0) - R²
//     double produtoC = biblioteca::ProdutoEscalar(C0P0,C0P0) - (this->raio*this->raio);

//     /*  Δ > 0 tem 2 intersecoes
//         Δ = 0 tem 1 intersecao
//         Δ < 0 tem 0 intersecoes */

//     double Delta = (produtoB*produtoB) - (produtoA)*(produtoC);

//     if (Delta > 0){

//         t_int1 = (-produtoB + sqrt(Delta))/produtoA;
//         t_int2 = (-produtoB - sqrt(Delta))/produtoA;
//         p_t_int1 = biblioteca::EquacaoDaReta(*pP0,t_int1,pV0N);
//         p_t_int2 = biblioteca::EquacaoDaReta(*pP0,t_int2,pV0N);
//         if(biblioteca::distanciaEntrePontos(p_t_int1,pP0) > biblioteca::distanciaEntrePontos(p_t_int2,pP0)) {
//             p_t_int1 = p_t_int2;
//         }
//     }

//     else if (Delta == 0){

//         t_int1 = (-produtoB + sqrt(Delta))/produtoA;
//         p_t_int1 = biblioteca::EquacaoDaReta(*pP0,t_int1,pV0N);
//     }

//     return make_tuple(p_t_int1, this);

// }

class esfera()
{
    
};