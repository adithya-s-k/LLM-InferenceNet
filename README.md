# LLM InferenceNet

LLM InferenceNet is a C++ based project designed to achieve fast inference from Large Language Models (LLMs) by leveraging a client-server architecture. The project aims to make it easier for deployment and to run optimized LLMs on edge devices, ensuring efficient interactions with pre-trained language models.

## Introduction

Language models such as LLaMa2 have shown exceptional capabilities in natural language processing tasks. However, running inference on these large models can be computationally intensive. LLM InferenceNet addresses this challenge by providing a C++ implementation that facilitates fast and efficient inference from pre-trained language models.

## Project Structure

The project is organized as follows:

-   /server: This directory contains the source code for the C++ implementation of the inference engine and HTTP server.
-   /models: In this directory, you can find pre-trained language models used for inference. (Note: Due to model size limitations, you will need to download and place the models in this directory before running the project.)
-   /docs: This folder contains documentation related to the project.
-   /examples: Explore this directory to find examples demonstrating how to interact with the inference engine and perform inference through the client-server architecture.

## To-Do List

The following are some of the key tasks that need to be addressed:

-   [ ] Implement the C++ inference engine to load and run pre-trained language models efficiently.
-   [ ] Design an API for the client-server communication to send input data to the server for inference.
-   [ ] Implement the HTTP server in C++ to handle client requests and responses.
-   [ ] Handle concurrent requests efficiently for improved performance.
-   [ ] Benchmark and optimize the inference process for faster execution.
-   [ ] Support edge devices and optimize LLMs for deployment on resource-constrained environments.
-   [ ] Explore model optimization techniques for better performance on edge devices.

Contributions to any of the above tasks or other improvements are highly welcome!

## Installation

To get started with LLM InferenceNet, follow these steps:

1. Clone the repository: `git clone https://github.com/adithya-s-k/LLM-InferenceNet.git`
2. Navigate to the project directory: `cd LLM-InferenceNet`
3. Install the required dependencies (TorchScript, Boost.Beast, etc.).
4. Download the pre-trained language models (e.g., LLAMA 2, Vicuna, MPT) and place them in the `models/` directory.
5. Build the project using the provided CMakeLists.txt file.
6. Run the HTTP server executable.

Detailed installation instructions and usage guidelines can be found in the `docs/` directory.

## Contribution

Contributions to LLM InferenceNet are highly appreciated. If you have any ideas, bug fixes, or enhancements, please feel free to open an issue or submit a pull request. Together, we can make this project even more powerful and efficient.

Let's work together to bring fast and optimized inference capabilities to large language models using C++ and the client-server architecture, enabling easier deployment on edge devices!
