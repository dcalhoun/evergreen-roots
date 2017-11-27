import Index from './Index.re';
import React, { Component } from 'react';
import { fetchListings } from '../utils/endpoints';

export default class extends Component {
  static async getInitialProps() {
    const resp = await fetchListings();
    const json = await resp.json();
    return { items: json.results };
  }

  render() {
    return <Index items={this.props.items} />;
  }
}
