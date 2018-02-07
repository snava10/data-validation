# data-validation

Data Validation is a general purpose data validation framework. Provided a validation schema and data, the program will return a list of errors with comprenhensive enough information for the user to correct the input.

# Validation Schema

The first step is to tell the program how to validate your data, this is achieved through a validation schema. The schema is a text file written in a specialy design language to create data validation rules. The language is essentially as defined here http://digital-preservation.github.io/csv-schema/csv-schema-1.1.html with some minor modifications. 

# Technology

## Schema Parser

The first step is to parse the schema, for that we have created an Antlr4 grammar and generated parser in C++ and Java.
The parser is implemented using an Antlr4 Listener.

## Validator

Given that the parser did not find any errors with the schema, the next step is to validate the input data. This is the task of the validator.

Currently a sub set of the validaton is implemented in the C++ version.

# API

The validation service will be available through a Rest Api which will support batch validation.

# Stream

A later phase of the project will support mini-batch and stream data validation.

# Schema Validation creation UI

A web base editor to write validation schemas. Supports autocompletion and syntax checking.

# Sample Usage

Request: 
Method: Post 
Url : http://validate-data.com
Body : {
  schema: "...your validation schema...",
  data: [
    { name: "Jon Snow",
      address: "Winterfell",
      age: 25,
      dateOfBirth: "None",
      house: "Stark"
     },
     {
      name: "Tyrion Lannister",
      address: "King's Landing".
      age: 35,
      dateOfBirth: 03/05/1285,
      house: "Lannister"
     }
  ]
}

Response:
{
  errors: [
    {
      document: 1,
      field: dateOfBirth,
      message: "None is not a valid Date"
    }
  ]
}


