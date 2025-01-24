from flask import * 
import requests
app = Flask(__name__)
@app.route('/lb',methods=['GET'])