from pymongo import MongoClient
from dotenv import load_dotenv
import os
from urllib.parse import quote_plus
from pprint import pprint

load_dotenv("../../.env")

mongo_user = quote_plus(os.getenv("MONGO_INITDB_ROOT_USERNAME") or '')
mongo_password = quote_plus(os.getenv("MONGO_INITDB_ROOT_PASSWORD") or '')

client = MongoClient(f'mongodb://{mongo_user}:{mongo_password}@mongo.docker/admin')

db = client.waf
record = db.normal_log.find_one({
    "request_headers.Host": {
        "$regex": ".*google.com"
    }
})

pprint(record)
