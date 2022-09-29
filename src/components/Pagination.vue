<template>
  <nav class="pagination">
    <div class="inner">
      <span class="page-number current">1</span>
      <a class="page-number" @click="nextPage">2</a>
      <span class="space">…</span>
      <a class="page-number" href="/page/22/">{{pageNum}}</a>
      <a class="extend next" rel="next" @click="nextPage">
        <i class="ic i-angle-right" aria-label="下一页"></i>
      </a>
    </div>
  </nav>
</template>
<script setup>
import { defineProps, toRefs, defineEmits } from 'vue'
import { RouterLink } from "vue-router";
const props = defineProps({
  pageNum: {
    type: Number,
    default: 0
  }
})

const { pageNum } = toRefs(props)

const nextPage = () => {

}
</script>
