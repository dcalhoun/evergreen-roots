import Index from './Index.re';
import PropTypes from 'prop-types';
import React, { Component } from 'react';
// TODO: Update Status.re to export wrap for JS
import * as status from '../lib/js/utils/Status';
import { fetchListings } from '../utils/endpoints';

export default class IndexPage extends Component {
  // TODO: Clean up error handling
  static async getInitialProps() {
    const defaultProps = { status: status.idle, items: [], error: {} };
    console.log('> START');
    if (typeof window === 'undefined') {
      let resp, json;
      try {
        resp = await fetchListings();
      } catch (error) {
        console.log('> ERROR: Network');
        return { ...defaultProps, error, status: status.error };
      }

      if (resp.ok) {
        try {
          json = await resp.json();
          console.log('> ERROR: JSON');
        } catch (error) {
          return { ...defaultProps, error, status: status.error };
        }
      } else {
        console.log('> ERROR: Not OK');
        return {
          ...defaultProps,
          error: { message: 'Failure' },
          status: status.error,
        };
      }

      console.log('> ERROR: None');
      return {
        ...defaultProps,
        status: status.fetched,
        items: json.results,
      };
    }
    return {
      ...defaultProps,
      status: status.idle,
      items: [],
    };
  }

  render() {
    return (
      <Index
        status={this.props.status}
        items={this.props.items}
        error={this.props.error}
      />
    );
  }
}

IndexPage.propTypes = {
  status: PropTypes.string,
  items: PropTypes.array,
  error: PropTypes.object,
};
