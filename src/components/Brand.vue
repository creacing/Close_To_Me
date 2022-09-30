

<template>
  <div class="inner">
    <div id="brand" class="affix">
      <div class="pjax">
        <RouterLink to="/" class="logo" rel="start">
          <p class="artboard">{{ author }}</p>
          <h1 class="title">{{ title }}</h1>
        </RouterLink>
        <p class="meta">{{ description }}</p>
      </div>
    </div>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
const { author, title, description } = config;
</script>