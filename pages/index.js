import Index from './Index.re';
import PropTypes from 'prop-types';
import React, { Component } from 'react';
import status from '../utils/status';
import { fetchListings } from '../utils/endpoints';

export default class IndexPage extends Component {
  static async getInitialProps() {
    if (typeof window === 'undefined') {
      const resp = await fetchListings();
      const json = await resp.json();
      return {
        status: status.FETCHED,
        items: json.results,
      };
    }
    return {
      status: status.IDLE,
      items: [],
    };
  }

  render() {
    return <Index status={this.props.status} items={this.props.items} />;
  }
}

IndexPage.propTypes = {
  status: PropTypes.string,
  items: PropTypes.array,
};
