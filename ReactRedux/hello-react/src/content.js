import React, { Component } from 'react';

class Content extends Component {
  render (){
    return(
        <div>
          <h1> Facebook Library </h1>
          
          <p>{this.props.title}</p>
          <p>{this.props.name}</p>
          <p>{this.props.occ}</p>


          <h1><a href="/">Home</a></h1>
        </div>  
      );
  }
}


export default Content;