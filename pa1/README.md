# Instruções para Compilação e Execução

Este projeto utiliza `make` para gerenciar o processo de compilação e execução. Siga as etapas abaixo para configurar e rodar o programa corretamente.

## Pré-requisitos

Antes de compilar e rodar o programa, é necessário garantir a existência das pastas `bin` e `obj`, que serão utilizadas para armazenar o executável e os arquivos objeto gerados. Para criá-las, execute os seguintes comandos no terminal a partir da pasta raiz do projeto:

```bash
    mkdir bin
    mkdir obj
```

## Comandos disponíveis

Após configurar as pastas, utilize os seguintes comandos para interagir com o projeto:

- **Compilar o projeto:**
    ```bash
    make all
    ```
    Este comando compila o projeto e gera os arquivos necessários.

- **Compilar e executar o programa:**
    ```bash
    make run
    ```
    Além de compilar, este comando também executa o programa a partir do executável gerado.

- **Limpar arquivos gerados:**
    ```bash
    make clean
    ```
    Remove todos os arquivos .o e o executável criado durante a compilação.

## Observações
- Certifique-se de que o make está instalado no seu sistema antes de prosseguir.
- As pastas bin e obj devem ser criadas apenas uma vez, antes da primeira compilação.
