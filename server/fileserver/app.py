from flask import Flask, render_template

app = Flask(__name__)

@app.route('/api/get_test', methods=['GET'])
def get_test():
    return {'message': 'This is a GET test API'}

@app.route('/api/post_test', methods=['POST'])
def post_test():
    return {'message': 'This is a POST test API'}

@app.route('/api/llm_test', methods=['GET', 'POST'])
def llm_test():
    return {'message': 'This is an LLM test API'}

if __name__ == '__main__':
    app.run(debug=True)
